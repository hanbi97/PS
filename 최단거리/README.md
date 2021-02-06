1. 다익스트라 - 거의 모든 문제에 사용 (1:n 경로)
2. 벨만포드 - 가중치에 음수 있을때
3. 플로이드 - n이 작을때(O(n^3)) (n:n 경로)

##### 다익스트라
* 그래프에 가중치 같이 저장
* 출발점에서 도착점까지 거리 저장하는 배열 선언, INF로 초기화
* dist[출발점], 출발점 정보 min PQ에 넣고 탐색 시작
* PQ pop = curr
	* curr 가중치 > dist[curr] = continue
	* curr에서 갈 수 있는점 = next 파악
	* dist[next] > next 가중치+curr 가중치면 dist 갱신


##### 벨만포드
* 정점 n개면 n-1번 연결된 edge 확인하고 가중치 갱신함 n번째에 사이클 유무 확인
* dist[start]=0
* 현재 정점 from에서 갈 수 있는 정점 to
	* dist[from]= INF = continue; <- 아직 이 점으로 가는 길을 아무도 찾지 못했음
	* dist[to] > dist[from] + cost면 dist[to] 갱신
* n-1번 돌아서 길 다 찾았는데 n번째에 dist[to] > dist[from] + cost면 사이클 있는것


##### 플로이드
* 인접행렬 이용 1->2, 2->4면 1->4
* 행렬 업데이트시 완전히 업데이트 되지 않은걸 사용하지 않도록 주의
* 인접 행렬에는 최단 거리만 들어가 있어야 함