# Wildfire Data Exploration & Visualization

## Project summary
This notebook loads a historical wildfires dataset from Australia, performs basic time-series and regional exploratory analysis, visualizes distributions and trends, and creates a Folium map with region markers.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Australia_Wildfire_Analysis.ipynb` — Notebook.
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

`jupyter notebook Australia_Wildfire_Analysis.ipynb`

4. Run the notebook cells from top to bottom.

---

## Notes & reproducibility
- If the Folium map does not render inline in your environment, save it with Aus_map.save("aus_map.html") and open that file in a browser.
