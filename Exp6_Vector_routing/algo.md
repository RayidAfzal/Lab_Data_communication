
# Algorithm: Distance Vector Routing

1. Start.
2. Read the number of nodes and the cost matrix.
3. Initialize each router's distance vector using the cost matrix.
4. Set each destination's next hop to itself.
5. Set count = 0.
6. For every router, destination, and intermediate node, check whether a shorter path exists.
7. If a shorter path exists, update the distance and next hop, and increment count.
8. Repeat steps 5–7 until count becomes 0.
9. Display the routing table of each router.
10. Stop.



# Pseudocode: Distance Vector Routing

START
    Read number of nodes n
    Read cost matrix

    FOR each router i
        FOR each destination j
            Set distance[i][j] = cost[i][j]
            Set next_hop[i][j] = j
        END FOR
    END FOR

    REPEAT
        Set count = 0

        FOR each router i
            FOR each destination j
                FOR each intermediate node k
                    IF distance[i][j] >
                       cost[i][k] + distance[k][j] THEN

                        Update distance[i][j]
                        Update next_hop[i][j]
                        Increment count
                    END IF
                END FOR
            END FOR
        END FOR
    UNTIL count = 0

    Display routing tables
STOP
