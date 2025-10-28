# Part 6: SpaceX Launches — Interactive Map & Proximity Analysis (Folium)

## Project summary  
This notebook loads SpaceX launch geolocation data, creates an interactive Folium map with launch-site markers and clustered launch events, colors markers by success/failure, and calculates distances from a selected launch site to nearby coastline/roads/rail/city points, visualizing them with lines and distance labels.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Files in this folder
- `Interactive_Visual_Analytics_Folium.ipynb` — Notebook (original code preserved; documentation added).  
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

4. Run cells top-to-bottom.

5. If Folium map does not render inline, save it with: `site_map.save("site_map.html")` and open `site_map.html` in a browser.

## Notes & reproducibility

- The notebook loads `spacex_launch_geo.csv` from a public URL; if the URL changes download the CSV and point `URL` to the local file.
- Folium plugins such as `MarkerCluster` and `MousePosition` are used; ensure the environment supports them (standard Jupyter does).
