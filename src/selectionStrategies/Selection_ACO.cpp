#include "Selection_ACO.h"

SelectionStrategiesRegister Selection_ACO::selectionStrategiesRegister("ACO", getInstance());

Selection_ACO * Selection_ACO::selection_ACO = 0;

Selection_ACO * Selection_ACO::getInstance() {
	if ( selection_ACO == 0 )
		selection_ACO = new Selection_ACO();
    
	return selection_ACO;
}

int Selection_ACO::apply(Router * router, const vector < int >&directions, const RouteData & route_data) {
    vector < int >neighbors_on_path;
    vector < int >score;
    int direction_selected = NOT_VALID;

    int current_id = route_data.current_id;

    for (size_t i = 0; i < directions.size(); i++) {
	// get id of adjacent candidate
	int candidate_id = router->getNeighborId(current_id, directions[i]);

	// apply routing function to the adjacent candidate node
	RouteData tmp_route_data;
	tmp_route_data.current_id = candidate_id;
	tmp_route_data.src_id = route_data.src_id;
	tmp_route_data.dst_id = route_data.dst_id;
	tmp_route_data.dir_in = router->reflexDirection(directions[i]);


	vector < int >next_candidate_channels =
	    router->routingFunction(tmp_route_data);

	// select useful data from Neighbor-on-Path input 
	ACO_data ACO_tmp = router->ACO_data_in[directions[i]].read();

	// store the score of node in the direction[i]
	score.push_back(router->ACOScore(ACO_tmp, next_candidate_channels));
    }

    // check for direction with higher score
    //int max_direction = directions[0];
    int max = score[0];
    for (unsigned int i = 0; i < directions.size(); i++) {
	if (score[i] > max) {
	//    max_direction = directions[i];
	    max = score[i];
	}
    }

    // if multiple direction have the same score = max, choose randomly.

    vector < int >equivalent_directions;

    for (unsigned int i = 0; i < directions.size(); i++)
	if (score[i] == max)
	    equivalent_directions.push_back(directions[i]);

    direction_selected =
	equivalent_directions[rand() % equivalent_directions.size()];

    return direction_selected;
}

void Selection_ACO::perCycleUpdate(Router * router) {
	    // update current input buffers level to neighbors
	    for (int i = 0; i < DIRECTIONS + 1; i++)
		router->free_slots[i].write(router->buffer[i].getCurrentFreeSlots());

	    // ACO selection: send neighbor info to each direction 'i'
	    ACO_data current_ACO_data = router->getCurrentACOData();

	    for (int i = 0; i < DIRECTIONS; i++)
		router->ACO_data_out[i].write(current_ACO_data);
}
