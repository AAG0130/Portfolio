# Automobile Sales Statistics Dashboard (Dash)

## Project summary
This Dash app provides an interactive dashboard to analyze historical automobile sales. Users can select either yearly statistics or recession-period statistics and explore visualizations such as time-series of average sales, vehicle-type comparisons, advertising expenditure shares, and the effect of unemployment on sales.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Automobile_Statistics_Dashboard.ipynb` — Notebook containing the Dash app.  
- `Automobile_Statistics_Dashboard_App.py` — (optional) Convert the Dash app cell(s) to a standalone script for deployment.  
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
