#ifndef __NOXIMSELECTION_ACO_H__
#define __NOXIMSELECTION_ACO_H__

#include "SelectionStrategy.h"
#include "SelectionStrategies.h"
#include "../Router.h"

using namespace std;

class Selection_ACO : SelectionStrategy {
	public:
        int apply(Router * router, const vector < int >&directions, const RouteData & route_data);
        void perCycleUpdate(Router * router);
        void perCycleAcoTableUpdate(Router * router,const int destinationId,const int chosenDirection);

		static Selection_ACO * getInstance();

	private:
		Selection_ACO(){};
		~Selection_ACO(){};

		static Selection_ACO * selection_ACO;
		static SelectionStrategiesRegister selectionStrategiesRegister;

		float reinforcement_factor;
		float alpha;
};

#endif
