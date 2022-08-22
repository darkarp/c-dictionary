#!/usr/bin/env python3
import calculations

MAXITER = 3000

ATOTAL = 4752
BTOTAL = 4753
CTOTAL = 4639

# ? factors of the numbers
afactors = calculations.factors(ATOTAL)
bfactors = calculations.factors(BTOTAL)
cfactors = calculations.factors(CTOTAL)


def returnlists(afcators, bfactors):
    aindex = calculations.generate_modulos(
        list(set(afactors + bfactors)), ATOTAL, MAXITER)
    bindex = calculations.generate_modulos(
        list(set(afactors + bfactors)), BTOTAL, MAXITER)
    cindex = calculations.generate_modulos(
        list(set(afactors + bfactors)), CTOTAL, MAXITER)
    return aindex, bindex, cindex


aindex, bindex, cindex = returnlists(afactors, bfactors)
acount = len(set(aindex))
bcount = len(set(bindex))
ccount = len(set(cindex))
acol = MAXITER-acount
bcol = MAXITER-bcount
ccol = MAXITER-ccount

acolpercent = 100*acol/MAXITER
bcolpercent = 100*bcol/MAXITER
ccolpercent = 100*ccol/MAXITER

print(f"## Number of collisions for {MAXITER} insertions ##\n")
print(f"Collisions in even non-primes = {ATOTAL}: {acol} ({acolpercent:.2f}%)")
print(f"Collisions in odd non-primes  = {BTOTAL}: {bcol} ({bcolpercent:.2f}%)")
print(f"Collisions in primes          = {CTOTAL}: {ccol} ({ccolpercent:.2f}%)")
