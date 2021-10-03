# Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3404/

class Solution(object):
	def leastInterval(tasks, n):
		"""
		@param: tasks: List
		@param: n: int
		"""
		max_freq, times = 0, 0
		hash_list = [0 for _ in range(26)]

		for each_char in tasks:
			hash_list[ord(each_char) - 65] += 1

		max_freq = max(hash_list)

		for i in range(26):
			if  max_freq == hash_list[i]:
				times += 1 

		answer = (max_freq-1)*n + max_freq
		answer += (times-1)
        	answer = max(answer, len(tasks))
        	return answer
