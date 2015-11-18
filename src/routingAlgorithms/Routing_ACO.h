#ifndef __NOXIMROUTING_ACO_H__
#define __NOXIMROUTING_ACO_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_ACO : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);

		static Routing_ACO * getInstance();

	private:
		Routing_ACO(){};
		~Routing_ACO(){};

		static Routing_ACO * routing_ACO;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
};

#endif
