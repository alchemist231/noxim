#include "Routing_ACO_TABLE.h"

int maximum(int x, int y) { return x>y ? x:y;}

RoutingAlgorithmsRegister Routing_ACO_TABLE::routingAlgorithmsRegister("ACO_TABLE", getInstance());

Routing_ACO_TABLE * Routing_ACO_TABLE::routing_ACO_TABLE = 0;

Routing_ACO_TABLE * Routing_ACO_TABLE::getInstance() {
	if ( routing_ACO_TABLE == 0 )
		routing_ACO_TABLE = new Routing_ACO_TABLE();

	return routing_ACO_TABLE;
}

vector<int> Routing_ACO_TABLE::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    int destinationID = routeData.dst_id;

    //Number of output channels => 4 Directions(N/E/S/W) + local hub + wireless
    int numberOfOutputChannels=router->outputChannelDirections;

    // could have used iterator in the following for loop than above numberOfOutputChannels usage
    for(int i=0 ; i<numberOfOutputChannels ; i++)
    {
        max = maximum(max,router->ACO_table[i][destinationID]);
    }

    

    return admissibleOutputsSet2Vector(ao);
}

vector<int> backwardRoute::route(Router * route, const RouteData & routeData)
{
    
}
