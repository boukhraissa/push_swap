import random
import subprocess

n = int(input("number of numbers -> "))
nn = int(input("number of max -> "))

for j in range(10**5):
    print("->", j)
    # Use a set for efficient unique number generation
    lst = set()
    while len(lst) < n:
        aid = random.randint(0, 500)
        lst.add(aid)
    text = "./push_swap " + " ".join(map(str, lst)) + " | wc -l"
    result = subprocess.run(text, shell=True, capture_output=True, text=True)
    # print(True)
    try:
        output = int(result.stdout.strip())
        if output >= nn:
            print(True)
            print(result.stdout)
            print(text)
            break
    except ValueError:
        print("Error in command output:", result.stdout)
