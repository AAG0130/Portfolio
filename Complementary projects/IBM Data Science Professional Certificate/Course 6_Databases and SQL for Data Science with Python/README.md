# Chicago Data Portal Exploration — Loading and Querying with SQLite

## Project summary
This notebook demonstrates how to load three CSV datasets (Chicago census, public schools, and crime data) into a local SQLite database (`FinalDB.db`) and use SQL queries to explore and answer a series of analytical questions.

**Important notice:** 

Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Chicago_Data_Portal_Exploration.ipynb` — The notebook.
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

`jupyter notebook Chicago_Final_Module_Notebook.ipynb`

4. Run the notebook cells from top to bottom. The notebook will:
- Create (or overwrite) `FinalDB.db` in the working directory,
- Load the CSV datasets into SQLite tables,
- Execute the provided SQL queries using the Pandas `read_sql_query` and display results inline.

---

## Notes & reproducibility
- The notebook downloads CSV files from public course URLs. To run offline, download the CSVs and modify the `pd.read_csv(...)` calls to point to local files.
- The notebook requires `ipython-sql` and `sqlalchemy` packages. Ensure they are installed (see `requirements.txt`).
- The database file `FinalDB.db` will be created in the notebook's working directory.
