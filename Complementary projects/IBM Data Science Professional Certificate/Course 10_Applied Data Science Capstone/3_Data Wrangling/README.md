# Part 3: SpaceX Launches — Data Wrangling

## Project summary 
This notebook loads the previously created SpaceX enriched dataset (`dataset_part_1.csv`), performs Exploratory Data Analysis (missing values, datatypes, value counts), defines a binary landing class from launch outcomes, and saves the processed table as `dataset_part_3.csv`.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `3_Data_Wrangling.ipynb` — Notebook.  
- `dataset_part_3.csv` — Processed CSV (generated after running the notebook).  
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

`jupyter notebook 3_Data_Wrangling.ipynb`

4. Run cells top-to-bottom. The notebook will:

* Load dataset_part_1.csv,
* Inspect basic statistics and counts,
* Create a binary Class label from Outcome,
* Save the processed data to dataset_part_3.csv.

## Notes & reproducibility

- The set of bad_outcomes is selected by index positions of value_counts() result; if the ordering of categories changes, re-check those indices before re-running.
