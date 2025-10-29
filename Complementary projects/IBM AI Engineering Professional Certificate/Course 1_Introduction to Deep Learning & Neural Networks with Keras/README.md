# Neural Network Regression on Concrete Data

## Project summary
This notebook trains and evaluates simple neural network regression models to predict concrete compressive strength. It compares a shallow network (one hidden layer) and a deeper network (three hidden layers), computes mean squared error (MSE) across repeated train/test splits, and reports mean and standard deviation of MSE.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `NeuralNetwork_Concrete_Models_Keras.ipynb` — Notebook.  
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

  `jupyter notebook NeuralNetwork_Concrete_Models_Keras.ipynb`

4. Run cells from top to bottom.

## Notes & reproducibility

- Multiple repetitions and epochs can be time-consuming — consider reducing repetitions or epochs for quicker runs.
