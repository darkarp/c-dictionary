import random
import calculations

MAXITER = 10000

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
acollisions = len(aindex)-acount
bcollisions = len(bindex)-bcount
ccollisions = len(cindex)-ccount

acolpercentage = 100*acollisions/MAXITER
bcolpercentage = 100*bcollisions/MAXITER
ccolpercentage = 100*ccollisions/MAXITER


print(f"Collisions in even non-primes: {acollisions} ({acolpercentage:.2f}%)")
print(f"Collisions in odd non-primes: {bcollisions} ({bcolpercentage:.2f}%)")
print(f"Collisions in primes: {ccollisions} ({ccolpercentage:.2f}%)")
