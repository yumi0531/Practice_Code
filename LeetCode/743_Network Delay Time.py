import heapq
from typing import List
from collections import defaultdict

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        '''1 <= k <= n <= 100'''
        
        # Build the graph as an adjacency list
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))  # (target, weight)
            
        # initialize distances 
        dist = {i: float('inf') for i in range(1, n + 1)}
        dist[k] = 0
        heap = [(0, k)]  # (distance, node) -> the distance from start to node
        
        while heap:
            # get the node with the smallest distance
            distance, u = heapq.heappop(heap) 
            
            if distance > dist[u]:
                continue
            
            # 探索 neighbors
            for v, w in graph[u]:
                if dist[v] > dist[u] + w :
                    dist[v] = dist[u] + w
                    heapq.heappush(heap, ((dist[v], v)))
                    
        max_time = max(dist.values())
        max_time = max_time if max_time != float('inf') else -1
        
        return max_time
        
        
        
if __name__ == "__main__":
    s = Solution()
    print("--- LeetCode 743. Network Delay Time ---")
    
    print("-"*20)
    print("Example 1:")
    times = [[2,1,1],[2,3,1],[3,4,1]]
    n = 4
    k = 2
    result = s.networkDelayTime(times, n, k) # Expected output: 2
    print(f"Result: {result}, Expected: 2")
    
    print("-"*20)
    print("Example 2:")
    times = [[1,2,1]]
    n = 2
    k = 1
    result = s.networkDelayTime(times, n, k) # Expected output: 1
    print(f"Result: {result}, Expected: 1")
    
    print("-"*20)
    print("Example 3:")
    times = [[1,2,1]]
    n = 2
    k = 2
    result = s.networkDelayTime(times, n, k) # Expected output: -1
    print(f"Result: {result}, Expected: -1")
    