class Solution(object):
    def backspaceCompare(self, s, t):
        x = list(s)
        y = list(t)
        for i in range(len(x)):
            if x[i] == '#':
                if i==0:
                    continue
                else:
                    x[i-1] = "#"
        for i in range(len(y)):
            if y[i] == '#':
                if i==0:
                    continue
                else:
                    y[i-1] = "#"
        for i in range(len(x)):
            if s[len(x)-i] == '#':
                x.pop(len(x)-i)
        for i in range(len(y)):
            if y[len(y)-i] == '#':
                y.pop(len(y)-i)
        return x==y