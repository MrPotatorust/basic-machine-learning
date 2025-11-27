import pandas as pd
import numpy as np


def predict(weight, bias, feature):
    return weight * feature + bias


bias = 0
weight = 0

loss_aggregate = 0
loss = 0


df = pd.read_csv('test.csv')

# Calculate loss
for (index, row) in df.iterrows():
    feature = row['pounds']
    label = row['miles_per_gallon']
    prediction = predict(weight, bias, feature)
    loss_aggregate += (label - prediction) ** 2


loss = loss_aggregate / len(df)
print(f"Loss: {loss}")

# Calculate derivative


