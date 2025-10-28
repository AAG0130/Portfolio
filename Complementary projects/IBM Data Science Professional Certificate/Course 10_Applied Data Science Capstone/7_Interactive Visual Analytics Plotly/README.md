# Part 7: SpaceX Launches - Records Dashboard Dash App

## Project summary  
This notebook contains a Dash application that visualizes SpaceX launch records. It provides interactive controls to filter by launch site and payload range, and displays a pie chart of successes and a scatter chart showing the correlation between payload mass and launch success.

**Important notice:**  
Documentation within this notebook was improved and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignment was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---


## Files in this folder
- `7_Interactive_Visual_Analytics_Plotly.ipynb` — Notebook.  
- `7_Interactive_Visual_Analytics_Plotly.py` — Dash App.  
- `requirements.txt` — Python packages required to run the app.

---

## How to run locally

1. Create and activate a Python virtual environment:

`python -m venv venv`
`source venv/bin/activate # macOS / Linux`
`venv\Scripts\activate # Windows`

2. Install dependencies:

`pip install -r requirements.txt`

3. Run the app:

* Run App: `python 7_Interactive_Visual_Analytics_Plotly.py`
* Run notebook. The server will run on `port 8054` by default. Open `http://127.0.0.1:8054/` in your browser.

## Notes & reproducibility

- Ensure `spacex_launch_dash.csv` is in the same folder or update the path accordingly.
