from typing import List
from collections import defaultdict

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        edge = []
        
        n = len(points)
        ds = DisjointSet(n)
        
        
        for i in range(n):
            for j in range(i + 1, n):
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edge.append([dist, i , j])
                
        edge.sort(key=lambda x: x[0])
        
        cost_sum = 0
        num_edge = n-1
        
        for dist, u, v in edge:
            if ds.find(u) != ds.find(v):
                ds.union(u, v)
                cost_sum += dist
                num_edge += 1
                
                if num_edge == n - 1:
                    break      
                
        return cost_sum
        
        
        
        
        
class DisjointSet:
    def __init__(self, n: int):
        self.parent = list(range(n)) # at the beginning, each node is its own parent
        self.rank = [0] * n # at the beginning, all nodes's rank is 0 
        self.count = n  # number of connected components

    def find(self, u: int) -> int:
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # path compression
        return self.parent[u]

    def union(self, u: int, v: int) -> bool:
        if self.find(u) != self.find(v):
            root_u = self.find(u)
            root_v = self.find(v)
            
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
    s = Solution()
    print("--- LeetCode 1584. Min Cost to Connect All Points ---")
    
    print("-"*20)
    print("Example 1:")
    points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    result = s.minCostConnectPoints(points) # Expected output: 20
    print(f"Result: {result}, Expected: 20")
    
    print("-"*20)
    print("Example 2:")
    points = [[3,12],[-2,5],[-4,1]]
    result = s.minCostConnectPoints(points) # Expected output: 18
    print(f"Result: {result}, Expected: 18")
    