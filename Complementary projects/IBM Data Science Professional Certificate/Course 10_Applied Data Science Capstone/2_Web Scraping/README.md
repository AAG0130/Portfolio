# Part 2: SpaceX Launches — Web Scraping & Table Extraction from Wikipedia

## Project summary 
This notebook scrapes a static Wikipedia revision of the "List of Falcon 9 and Falcon Heavy launches", extracts structured launch information (flight number, date/time, booster version, launch site, payload, mass, orbit, customer, outcome, landing status), and saves the cleaned table as CSV files.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `2_Web_Scraping.ipynb` — Notebook.
- `dataset_part_2.csv` — CSV produced by the scraping (after running).
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

`jupyter notebook 2_Web_Scraping.ipynb`

4. Run cells top-to-bottom. The notebook will:

* Fetch the static Wikipedia revision HTML,
* Parse the launch tables and extract fields,
* Save the result as dataset_part_2.csv.

## Notes & reproducibility

- The notebook uses a static Wikipedia revision (via oldid in the URL) to improve reproducibility. If you use another revision the table structure or content may differ and parsing functions may need adjustment.
