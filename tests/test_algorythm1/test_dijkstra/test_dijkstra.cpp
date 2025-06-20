#include <gtest/gtest.h>
#include "dijkstra.h"

TEST(DijkstraTest, DirectPath) {
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);

    EXPECT_EQ(g.dijkstra(0, 1).toStdString(), "0 -> 2 -> 1 (length 3)");
}

TEST(DijkstraTest, NoPath) {
    Graph g;
    g.addEdge(0, 1, 5);

    EXPECT_EQ(g.dijkstra(1, 2).toStdString(), "No path from 1 to 2");
}

TEST(DijkstraTest, PathThroughMultipleNodes) {
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 3, 10);

    EXPECT_EQ(g.dijkstra(0, 3).toStdString(), "0 -> 1 -> 2 -> 3 (length 6)");
}

TEST(DijkstraTest, SameStartEnd) {
    Graph g;

    EXPECT_EQ(g.dijkstra(5, 5).toStdString(), "5 (length 0)");
}

TEST(DijkstraTest, UnreachableNodeInGraph) {
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);

    EXPECT_EQ(g.dijkstra(0, 3).toStdString(), "No path from 0 to 3");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}