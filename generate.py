# while true; do RLIST=$(python generate.py) && ./push_swap $RLIST | wc -l; ./push_swap $RLIST | ./checker_Mac $RLIST; sleep 1; done
import random
print(" ".join([str(random.randint(-10000000, 10000000)) for _ in range(100)]))