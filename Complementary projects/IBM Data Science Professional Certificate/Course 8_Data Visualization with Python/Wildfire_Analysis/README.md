# Wildfire Data Exploration & Visualization

## Project summary
This notebook loads a historical wildfires dataset from Australia, derives Year and Month features, and performs temporal and regional exploratory analyses. It visualizes trends (estimated fire area), brightness distributions, relationships between radiative power and confidence, and produces a Folium map marking Australian regions.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Australia_Wildfire_Analysis.ipynb` — Notebook (documentation added; original code preserved).
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

---

## Notes & reproducibility
- The notebook uses from js import fetch and await fetch(...) which require a JavaScript-enabled notebook environment (e.g., JupyterLite/pyodide). For local CPython environments, you can replace the fetch block with: `df = pd.read_csv(URL)`
- If the Folium map does not render inline in your environment, save it with Aus_map.save("aus_map.html") and open that file in a browser.
- If you choose to modify the fetch approach for local execution, the rest of the code should work after installing the packages in requirements.txt.
