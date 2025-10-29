# Part 8: SpaceX Launches - Model Selection and Evaluation

## Project summary  
This notebook performs model selection and evaluation for launch-landing classification. It standardizes features, splits data into train/test sets, runs grid-search cross-validation to tune hyperparameters for Logistic Regression, SVM, Decision Tree and KNN, displays confusion matrices and compares final test accuracies.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `8_Predictive_Analysis.ipynb` — Notebook.  
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

`jupyter notebook 8_Predictive_Analysis.ipynb`

4. Run cells top-to-bottom.

## Notes & reproducibility

- The notebook uses course-hosted CSV URLs — if offline, download the CSVs and update the paths.
- GridSearchCV with many parameter combinations and 10-fold CV can be computationally intensive; consider reducing parameter grids or CV folds for faster iteration.
