# Python benchmarking

import datetime

discharge = 15.0
channel_slope = 0.001
n_manning = 0.015
base_width = 10.0

water_depth = 0.0
trial_discharge = 0.0

timestamp = datetime.datetime.now()

while trial_discharge < discharge:
    p = base_width + 2 * water_depth
    a = base_width * water_depth
    r = a / p
    v = (1 / n_manning) * pow(r, (2.0/3.0)) * pow(channel_slope, 0.5)
    trial_discharge = v * a
    water_depth += 0.00001

timestamp2 = datetime.datetime.now()
delta = timestamp2 - timestamp
diff = delta.total_seconds() * 1000

print("Calculation using python:")
print("Water depth:", round(water_depth, 3))
print("Time in milliseconds:", diff)
print("==========")