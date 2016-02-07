#include "Selection_ACO.h"

SelectionStrategiesRegister Selection_ACO::selectionStrategiesRegister("ACO", getInstance());

Selection_ACO * Selection_ACO::selection_ACO = 0;

Selection_ACO * Selection_ACO::getInstance() {
	if ( selection_ACO == 0 )
		selection_ACO = new Selection_ACO();
    
	return selection_ACO;
}

int Selection_ACO::apply(Router * router, const vector < int >&directions, const RouteData & route_data){
    assert(directions.size()!=0);

    int output = directions[rand() % directions.size()];
    return output;

}

void Selection_ACO::perCycleUpdate(Router * router){ }
