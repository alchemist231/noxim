#include "Selection_ACO.h"

float maximum(float x, float y) { return x>y ? x:y;}

SelectionStrategiesRegister Selection_ACO::selectionStrategiesRegister("ACO", getInstance());

Selection_ACO * Selection_ACO::selection_ACO = 0;

Selection_ACO * Selection_ACO::getInstance() {
	if ( selection_ACO == 0 )
		selection_ACO = new Selection_ACO();
    
	return selection_ACO;
}

int Selection_ACO::apply(Router * router, const vector < int >&directions, const RouteData & route_data){
    assert(directions.size()!=0);

    float max_prob 		= -10000;
    float current_prob  = 0;
    int max_prob_link	= 0;
    int destination_id 	= route_data.dst_id;

    // P'(j,d) = { P(j,d) + a*L }/{1 + a*(N-1)}
    float modified_current_prob = 0;
    int neighbor_buffer_length  = 0;

    for(int i=0; i<directions.size(); i++)
    {
    	current_prob = router->aco_table[directions[i]][destination_id];
    	neighbor_buffer_length = router->free_slots_neighbor[directions[i]];

    	if(neighbor_buffer_length!=0)
    	{ modified_current_prob = (current_prob + alpha * (1/neighbor_buffer_length))/( 1 + alpha*(directions.size()-1)); }

    	if(max_prob < modified_current_prob)
    	{
    		max_prob = modified_current_prob;
    		max_prob_link = directions[i];
    	}
    }

    perCycleAcoTableUpdate(router, destination_id, max_prob_link);
    return max_prob_link;

}

void Selection_ACO::perCycleUpdate(Router * router)
{
	
	
}

void Selection_ACO::perCycleAcoTableUpdate(Router * router,const int destinationId,const int chosenDirection)
{
	float current_prob = 0;

	for(int i=0 ; i<4 ; i++)
	{
		current_prob = router -> aco_table[i][destinationId] ;
		if(i==chosenDirection)
			{ router->aco_table[i][destinationId] = current_prob + reinforcement_factor * (1 - current_prob); }
		else
			{ router->aco_table[i][destinationId] = current_prob + reinforcement_factor * current_prob ; }
	}
}

