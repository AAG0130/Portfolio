# Part 5: SpaceX Launches - Visualization & Feature Engineering

## Project summary 
This notebook loads `dataset_part_2.csv` (SpaceX launch data), produces exploratory visualizations (payload, flight number, orbit, launch site, yearly success rate) with Seaborn/Matplotlib, and performs basic feature-engineering (one-hot encoding and export of `dataset_part_3.csv`).

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `5_EDA_Data_Visualization.ipynb` — Notebook (documentation added; code preserved).  
- `requirements.txt` — Python packages required to run the notebook.  
- `dataset_part_3.csv` — Exported features CSV (generated after running; note: original filename in code contains a backslash before underscore).

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
   
* Produce visualizations.
* Export the features table as CSV.

## Notes & reproducibility

- The notebook downloads dataset_part_2.csv from a course URL — if that URL changes, download the file and update the URL variable to a local path.
