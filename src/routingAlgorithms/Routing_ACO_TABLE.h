#ifndef __NOXIMROUTING_ACO_TABLE_H__
#define __NOXIMROUTING_ACO_TABLE_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

#include "../GlobalRoutingTable.h"

using namespace std;

class Routing_ACO_TABLE : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);
		vector<int> backwardRoute(Router * router, const RouteData & routeData);
		bool neighborInVisited(const vector<int> visited, const int neighborID);

		static Routing_ACO_TABLE * getInstance();

        inline string name() { return "Routing_ACO_TABLE";};

	private:
		Routing_ACO_TABLE(){};
		~Routing_ACO_TABLE(){};

		static Routing_ACO_TABLE * routing_ACO_TABLE;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
};

#endif
