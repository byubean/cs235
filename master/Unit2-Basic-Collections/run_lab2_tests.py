import json

print("Running Lab 2 Tests")

report = {
    "score": 0,
    "output": "The autograder hasn't been finished yet. Your submission will be regraded when it is ready"
}

with open("results.json", 'wt') as f:
    json.dump(report, f)
