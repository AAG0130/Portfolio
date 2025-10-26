# Historical Stock Price and Revenue Analysis — Tesla & GameStop

## Project summary
This notebook downloads historical stock price data (via `yfinance`) and quarterly revenue tables (from provided HTML pages), cleans the data, and visualizes price vs revenue for Tesla and GameStop.

**Important notice:** 

Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Stock_Revenue_Analysis.ipynb` — Notebook.
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

  `jupyter notebook Stock_Revenue_Analysis.ipynb`

4. Run cells from top to bottom.

---

## Notes & reproducibility
- The notebook requires an active internet connection to download data from `yfinance` and to read the HTML pages used for revenue tables.
- If you prefer offline execution, download the referenced HTML pages or revenue CSVs and replace the URL references with local file paths in the notebook.
- The notebook expects that the HTML pages contain revenue tables in the same structure as the course resources. If the HTML structure changes, the revenue extraction may need adjustments.
- If `pandas.read_html` raises an error, ensure `lxml` or `html5lib` is installed.
