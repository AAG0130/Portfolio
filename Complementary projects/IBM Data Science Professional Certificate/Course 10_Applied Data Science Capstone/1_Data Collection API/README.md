# Part 1: SpaceX Launches — Data Enrichment & Dataset Preparation

## Project summary 
This notebook retrieves historical SpaceX launch records, enriches them by calling SpaceX API endpoints (rockets, payloads, launchpads, cores), and produces a clean CSV dataset containing one-row-per-launch with key features (booster version, payload mass, orbit, launch site, core reuse stats, geolocation, etc.).

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Data_Collection_API.ipynb` — Notebook.
- `dataset_part_1.csv` — Enriched CSV (generated after running the notebook).
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

`jupyter notebook Data_Collection_API.ipynb`

4. Run cells top-to-bottom. The notebook will:

* Call SpaceX API endpoints (ensure internet access),
* Enrich launch records and assemble the enriched DataFrame,
* Save the result as dataset_part_1.csv.

## Notes & reproducibility

- The SpaceX public API is used. If the API structure changes, helper functions may need minor updates.
- To avoid repeated network traffic and to improve reproducibility, consider saving the raw API JSON responses locally (cache) and using them for re-runs.
- This notebook uses live HTTP calls.
