syms s
s = tf('s')
GP = 1/(1+3*s)^2
GC = 3*(1+1/(2*s))
GCGP = GC* GP
GTOT = feedback(GCGP,1)
step(GTOT)
stepinfo(GTOT)