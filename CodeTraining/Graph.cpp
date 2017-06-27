//
//  Graph.cpp
//  CodeTraining
//
//  Created by 宣松辰 on 27/04/2017.
//  Copyright © 2017 宣松辰. All rights reserved.
//

#include "Graph.hpp"

void ConvertToMGraph(ALGraph &G, int m, int n, int arcs[MaxVertexNum][MaxVertexNum]) {
    ArcNode *p;
    for (int i = 0; i < n; i++) {
        p = (G.vertices[i].first);
        while (p) {
            arcs[i][p->adjvex] = 1;
            p = p->next;
        }
    }
}


