#include "Routing_ACO.h"

RoutingAlgorithmsRegister Routing_ACO::routingAlgorithmsRegister("ACO", getInstance());

Routing_ACO * Routing_ACO::routing_ACO = 0;

Routing_ACO * Routing_ACO::getInstance() {
	if ( routing_ACO == 0 )
		routing_ACO = new Routing_ACO();
    
	return routing_ACO;
}

vector<int> Routing_ACO::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    vector <int> directions;

    if (destination.x > current.x)
        directions.push_back(DIRECTION_EAST);
    else if (destination.x < current.x)
        directions.push_back(DIRECTION_WEST);
    else if (destination.y > current.y)
        directions.push_back(DIRECTION_SOUTH);
    else
        directions.push_back(DIRECTION_NORTH);

    return directions;
}
