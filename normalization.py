import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt


#total_bill = float => float
#tip = float => float
#sex = str => int (Male: 0, Female: 1)
#smoker = str => int (No: 0, Yes: 1)
#day = str => int (Thur: 0, Fri: 1, Sat: 2, Sun: 3)
#time = str => int (Lunch: 0, Dinner: 1)
#size = int => int


def main():
    df = pd.read_csv('./dataset/tips.csv')

    normalizedDf = df.replace({
        'sex': {'Male': 0, 'Female': 1},
        'smoker': {'No': 0, 'Yes': 1},
        'day': {'Thur': 0, 'Fri': 1, 'Sat': 2, 'Sun': 3},
        'time': {'Lunch': 0, 'Dinner': 1}
    })

    normalizedDf.to_csv('./dataset/normalized_tips.csv', index=False)

if __name__ == "__main__":
    main()
