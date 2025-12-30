class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        ds = DisjointSet(grid)
        print(ds.count)
        
        # 2D -> 1D : r * cols + c
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    # check right
                    if c + 1 < cols and grid[r][c + 1] == "1":
                        ds.union(r * cols + c, r * cols + c + 1)

                    # check down
                    if r + 1 < rows and grid[r + 1][c] == "1":
                        ds.union(r * cols + c, (r + 1) * cols + c)
        
        return ds.count


class DisjointSet:
    def __init__(self, grid):
        
        m, n = len(grid), len(grid[0])
        
        # Index : node
        # value : parent index
        self.parent = list(range(m * n))
        
        self.rank = [0] * (m * n) # rank: height (or depth) of the tree rooted at this node.
        self.count = 0 # number of islands
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    self.count += 1

    def find(self, u):
        # find the root of the set in which element u is
        if self.parent[u] == u:
            return u
        else:
            # path compression optimization
            # make the parent of the nodes in the path point to the root, avoid to find all the parents
            self.parent[u] = self.find(self.parent[u])
            return self.parent[u]
        
    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        
        if root_u != root_v:
            # union by rank
            # attach smaller rank tree under root of higher rank tree -> keep the rank will not change too much
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1
            
            self.count -= 1
            
            return True
        return False
    
        
if __name__ == "__main__":
    
    sol = Solution()


    test_grid1 = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]
    ]
    

    test_grid2 = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]

    print("--- LeetCode 200. Number of Islands ---")
    
    result1 = sol.numIslands(test_grid1)
    print(f"Test Case 1 Result: {result1} (Expected: 1)")

    result2 = sol.numIslands(test_grid2)
    print(f"Test Case 2 Result: {result2} (Expected: 3)")