# Part 4: SpaceX Launches — Data Exploration with SQL

## Project summary  
This notebook loads a SpaceX CSV into a local SQLite database, creates a SQL table, and runs a sequence of SQL queries (SELECT DISTINCT, LIKE, SUM, AVG, MIN, BETWEEN, GROUP BY, subqueries, substring filters, ordering) to explore and summarize launch data.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `4_EDA_SQL.ipynb` — Notebook (original code preserved; docs added).  
- `my_data1.db` — Generated SQLite database (created when the notebook runs).  
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

`jupyter notebook 4_EDA_SQL.ipynb`

4. Run cells top-to-bottom. The notebook will:
   
* Create my_data1.db in the working directory,
* Save DataFrame to SPACEXTBL (SQL table),
* Execute multiple SQL queries and print results.

## Notes & reproducibility

- The notebook relies on the CSV URL provided by the course; if that URL becomes unavailable, download the CSV and update the pd.read_csv(...) source accordingly.
- SQLite date handling and string formats can be tricky. If you need more robust date filtering, consider converting the date column to DATE type in SQL or normalizing date formats in pandas before saving to SQL.
