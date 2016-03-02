#include "Routing_ACO_TABLE.h"

RoutingAlgorithmsRegister Routing_ACO_TABLE::routingAlgorithmsRegister("ACO_TABLE", getInstance());

Routing_ACO_TABLE * Routing_ACO_TABLE::routing_ACO_TABLE = 0;

Routing_ACO_TABLE * Routing_ACO_TABLE::getInstance() {
	if ( routing_ACO_TABLE == 0 )
		routing_ACO_TABLE = new Routing_ACO_TABLE();

	return routing_ACO_TABLE;
}

vector<int> Routing_ACO_TABLE::route(Router * router, const RouteData & routeData)
{
    Coord current     = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    int current_id     = routeData.current_id;
    int destination_id = routeData.dst_id;

    int neighbor_id;

    //Number of output channels => 4 Directions(N/E/S/W) + local hub + wireless
    int numberOfOutputChannels=router->outputChannelDirections;

    vector<int> directions;

    // check if need to iterate over 4+2 or only 4
    for(int i=0 ; i<4 ; i++)
    {
        neighbor_id = router->getNeighborId(current_id, i);
        
        if(neighbor_id!=NOT_VALID) 
        {
            if(router->free_slots_neighbor[i]!=NOT_VALID && !neighborInVisited(routeData.visited, neighbor_id))
                { directions.push_back(i); }
        }
    }

    //Since RouteData const , append visited node in router.cpp :: txProcess() itself
    //routeData.visited.push_back(routeData.current_id);

    return directions;
}

vector<int> Routing_ACO_TABLE::backwardRoute(Router * route, const RouteData & routeData)
{
    
}

bool Routing_ACO_TABLE::neighborInVisited(const vector<int> visited, const int neighborID)
{
    for(int i=0; i<visited.size() ; i++)
    {
        if(neighborID == visited[i]) {return true;}
    }

    return false;
}
