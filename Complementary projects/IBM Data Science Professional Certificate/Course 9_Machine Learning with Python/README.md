# Weather ML Models — Classification & Regression Report

## Project summary
This notebook loads an Australian Government's Bureau of Meteorology dataset, performs preprocessing (one-hot encoding and numeric casting), trains several models (Linear Regression, KNN, Decision Tree, Logistic Regression, SVM) and reports evaluation metrics (MAE, MSE, R2 for regression; Accuracy, Jaccard, F1, LogLoss for classification).

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Australia_Weather_Classification.ipynb` — Notebook.
- `requirements.txt` — Python packages required to run the notebook.

---

## How to run locally

1. Create and activate a Python virtual environment:

  `python -m venv venv`

  `source venv/bin/activate # macOS / Linux`

  `venv\Scripts\activate # Windows`

2. Install dependencies:

  `pip install -r requirements.txt`

3. Start Jupyter Notebook:

  `jupyter notebook Australia_Weather_Classification.ipynb`

4. Run cells from top to bottom.
