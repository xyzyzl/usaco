n = int(input())
adj_lst = [list() for i in range(n)]
# amount visited from ith node down
dp1 = [0 for i in range(n)]
# amount skipped from ith node down
dp2 = [0 for i in range(n)]
# cur is current node
# pre is node that cur came from (or -1 if cur is root)
def dp(cur, pre) :
	dp1[cur] = 1
	dp2[cur] = 0
	for i in range(len(adj_lst[cur])) :
		nx = adj_lst[cur][i]
		# don't revisit parent
		if(nx == pre) :
			continue
		# go to next point
		dp(nx, cur)
		# only possibility for a visited root is an unvisited child
		dp1[cur] += dp2[nx]
		# if root is not visited, child can be either visited or not
		dp2[cur] += max(dp1[nx], dp2[nx])
for i in range(n-1) :
	c1, c2 = input().split(" ")
	c1 = int(c1)
	c2 = int(c2)
	c1 -= 1
	c2 -= 1
	adj_lst[c1].append(c2)
	adj_lst[c2].append(c1)
# root node has no parent
dp(0, -1)
# both values are interchangeable
print("%d" % max(dp1[0], dp2[0]))
