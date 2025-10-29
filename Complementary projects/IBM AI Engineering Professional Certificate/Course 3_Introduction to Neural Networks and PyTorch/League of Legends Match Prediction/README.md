# League of Legends Match Outcome Predictor — PyTorch Logistic Regression

## Project summary   
This notebook trains and evaluates a logistic regression classifier (implemented in PyTorch) to predict match outcomes (win/loss) from match-level features in a League of Legends dataset. It includes data loading and preprocessing, model implementation, training, optimization, evaluation, visualization, model saving and loading, hyperparameter tuning, and feature importance analysis.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `League_of_Legends_Match_Predictor.ipynb` — Notebook.  
- `league_of_legends_data_large.csv` — Dataset required by the notebook.  
- `model.pth` — Saved model after running.  
- `requirements.txt` — Python packages required to run the notebook.

## How to run locally

1. Create and activate a Python virtual environment:

`python -m venv venv`
`source venv/bin/activate # macOS / Linux`
`venv\Scripts\activate # Windows`

2. Install dependencies:

`pip install -r requirements.txt`

3. Start Jupyter Notebook:

`jupyter notebook League_of_Legends_Match_Predictor.ipynb`

4. Run cells top-to-bottom.

## Notes & reproducibility

- Ensure `league_of_legends_data_large.csv` is accessible in the working directory.  
- The notebook trains multiple models and runs a learning-rate sweep — this can be time-consuming on CPU. Consider reducing epochs or sample sizes for quick testing.  
