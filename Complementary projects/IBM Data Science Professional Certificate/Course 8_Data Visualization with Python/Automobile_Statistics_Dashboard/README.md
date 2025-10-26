# Automobile Sales Dashboard — Interactive Dash App

## Project summary
This notebook builds a Dash interactive dashboard to explore historical automobile sales, showing both yearly statistics and recession-period analyses with multiple interactive visualizations.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Automobile_Statistics_Dashboard.ipynb` — Notebook.  
- `Automobile_Statistics_Dashboard_App.py` — Standalone script for Dash app deployment.  
- `requirements.txt` — Python packages required to run the app.

---

## How to run locally
1. Create and activate a Python virtual environment:

`python -m venv venv`
`source venv/bin/activate # macOS / Linux`
`venv\Scripts\activate # Windows`

2. Install dependencies:

`pip install -r requirements.txt`

3. Run the app:

`python Automobile_Statistics_Dashboard_App.py`

Then open the provided local URL (usually http://127.0.0.1:8050/) in your browser.

---

## Notes & reproducibility
- The data is loaded from the provided public CSV URL. Ensure the deployment environment can access that URL or include a local copy.
