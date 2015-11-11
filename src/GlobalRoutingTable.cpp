/*
 * Noxim - the NoC Simulator
 *
 * (C) 2005-2015 by the University of Catania
 * For the complete list of authors refer to file ../doc/AUTHORS.txt
 * For the license applied to these sources refer to file ../doc/LICENSE.txt
 *
 * This file contains the implementation of the global routing table
 */

#include "GlobalRoutingTable.h"
#include "myParam.h"

using namespace std;

LinkId direction2ILinkId(const int node_id, const int dir)
{
    int node_src;

    switch (dir) {
    case DIRECTION_NORTH:
	node_src = node_id - GlobalParams::mesh_dim_x;
	break;

    case DIRECTION_SOUTH:
	node_src = node_id + GlobalParams::mesh_dim_x;
	break;

    case DIRECTION_EAST:
	node_src = node_id + 1;
	break;

    case DIRECTION_WEST:
	node_src = node_id - 1;
	break;

    case DIRECTION_LOCAL:
	node_src = node_id;
	break;

    default:
	assert(false);
    }


    return LinkId(node_src, node_id);
}

int oLinkId2Direction(const LinkId & out_link)
{
    int src = out_link.first;
    int dst = out_link.second;

    if (dst == src)
	return DIRECTION_LOCAL;
    else if (dst == src + 1)
	return DIRECTION_EAST;
    else if (dst == src - 1)
	return DIRECTION_WEST;
    else if (dst == src - GlobalParams::mesh_dim_x)
	return DIRECTION_NORTH;
    else if (dst == src + GlobalParams::mesh_dim_x)
	return DIRECTION_SOUTH;
    else
	assert(false);
    return 0;
}

vector <
    int >admissibleOutputsSet2Vector(const AdmissibleOutputs & ao)
{
    vector < int >dirs;

    for (AdmissibleOutputs::iterator i = ao.begin(); i != ao.end();
	 i++)
	dirs.push_back(oLinkId2Direction(*i));

    return dirs;
}

GlobalRoutingTable::GlobalRoutingTable()
{
    valid = false;
    if(globalTraceRoutingTable==true) { cout<<"Global Routing Table created "<<endl;}
}

bool GlobalRoutingTable::load(const char *fname)
{
    ifstream fin(fname, ios::in);

    if(globalTraceRoutingTable==true) { cout<<"Loading global Routing table: "<<fname<<endl;}

    if (!fin)
	return false;

    rt_noc.clear();

    bool stop = false;
    while (!fin.eof() && !stop) {
	char line[128];
	fin.getline(line, sizeof(line) - 1);

	if (line[0] == '\0')
	    stop = true;
	else {
	    if (line[0] != '%') {
		int node_id, in_src, in_dst, dst_id, out_src, out_dst;

		if (sscanf
		    (line + 1, "%d %d->%d %d", &node_id, &in_src, &in_dst,
		     &dst_id) == 4) {
		    LinkId lin(in_src, in_dst);

		    char *pstr = line + COLUMN_AOC;
		    while (sscanf(pstr, "%d->%d", &out_src, &out_dst) == 2) {
			LinkId lout(out_src, out_dst);

			rt_noc[node_id][lin][dst_id].insert(lout);

			pstr = strstr(pstr, ",");
			pstr++;
		    }
		}
	    }
	}
    }

    valid = true;

    return true;
}



void printSet(set<LinkId> mySet)     // set of admissibleOutputs => pair of int,int
{
	cout<<"printing admissible outputs"<<endl;
	for(set<LinkId> :: iterator iter=mySet.begin() ; iter!=mySet.end(); iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

void printRoutingTableLink(RoutingTableLink rt_link)		//map<int, Admissible_outputs(==>set(LinkIds))
{
	cout<<"printing RoutingTableLink"<<endl;
	for(RoutingTableLink :: iterator iter=rt_link.begin(); iter!=rt_link.end(); iter++)
	{
		cout<<iter->first<<" : ";
		//printSet(iter->second);
	}
}

void printRoutingTableNode(RoutingTableNode rt_node)		//map(LinkId,RoutingTableLink)
{
	for(RoutingTableNode :: iterator iter=rt_node.begin(); iter!=rt_node.end(); iter++)
	{
		//printSet(iter->first);
		printRoutingTableLink(iter->second);
	}
}



void printRoutingTableNoC(RoutingTableNoC rt_noc )
{
	cout<<"printing rt_noc"<<endl;
	for(RoutingTableNoC :: iterator iter=rt_noc.begin(); iter!=rt_noc.end(); iter++)
	{
		cout<<iter->first<<" : ";
		printRoutingTableNode(iter->second);
	}
}

RoutingTableNode GlobalRoutingTable::
getNodeRoutingTable(const int node_id)
{
	if(globalTraceRoutingTable==true)
		{printRoutingTableNoC(rt_noc);}

    return rt_noc[node_id];
}
