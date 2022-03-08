#!/bin/python3

from sys import stdin
from math import log, floor

MAX_RESISTORS = 2

def expand(input):
  input = input.lower()
  result = 0.0
  multiplier = 1
  multipliers = {
      'k': 1e3,
      'm': 1e6
  }
  if not input[-1].isdigit():
    multiplier = multipliers.get(input[-1]) or 1
    input = input[:-1]
  result = float(input)
  return result * multiplier

def get_available():
  with open("./available", 'r') as file:
    content = file.readlines()
    return [expand(line.strip()) for line in content]

def calc_resistors(target, available):
  resistors = []
  for x in range(MAX_RESISTORS):
    for resistor in available:
      if resistor > target: continue
      target -= resistor
      resistors.append(resistor)
      break
  return resistors

def format_resistor_value(num):
  multipliers = ['', 'k', 'm']
  multiplier = floor(log(num, 1e3))
  return f"{(num / (1e3 ** multiplier)):.1f}{multipliers[multiplier]}"

def pretty_print(values, target):
  pretty_values = [format_resistor_value(res) for res in values]
  print(f"{' + '.join(pretty_values)} = {sum(values):.1f} Ohm  -->  off by {(sum(values) - target):.1f}")

def main():
  available = get_available()
  available.sort(reverse=True)
  for line in stdin:
    if line == '': break
    line = line.strip()
    resistors = calc_resistors(float(line), available)
    pretty_print(resistors, float(line))

if __name__ == "__main__":
  main()
