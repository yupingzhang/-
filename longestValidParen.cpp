// Longest Valid Parentheses 

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

# 
# Input:	"()(())"
# Expected:	6


class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        longest = 0
        stack = []
        last = -1
        
        for i in xrange(0,len(s)):
             if s[i] == '(': 
                 stack.append(i)       # push the INDEX into the stack
             else:
                 if stack == []:
                     last = i
                 else:
                     stack.pop()
                     if stack == []:
                         longest = max(longest, i-last)
                     else:
                         longest = max(longest, i-stack[len(stack)-1])
                     
        return longest
