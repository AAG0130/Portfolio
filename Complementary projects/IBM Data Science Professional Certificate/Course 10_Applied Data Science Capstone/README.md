# **Space X  Falcon 9 First Stage Landing Prediction**

## Project background and context
SpaceX has gained worldwide attention for a series of historic milestones. It is the only private company ever to return a spacecraft from low-earth orbit, which it first accomplished in December 2010. SpaceX advertises Falcon 9 rocket launches on its website with a cost of 62 million dollars, whereas other providers cost upward of 165 million dollars each; much of the savings is because SpaceX can reuse the first stage. Therefore, if we can determine if the first stage will land by training different machine learning models, we can determine the cost of a launch. This information can be used if an alternate company wants to bid against SpaceX for a rocket launch.

**Important notice:**  
Documentation within these notebooks was improved, and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignments was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Questions to answer

* What factors determine if the rocket will land successfully?
* What is the interaction among the features that determine the success rate of a successful landing?
* Which machine learning model will have the best predictive performance?

## Summary of methodologies

1. **Data Collection:** Request from the SpaceX API and extraction of the Falcon 9 launch records HTML table from Wikipedia.
2. **Data Wrangling:** Exploratory data analysis and training labels selection using pandas and SQL.
3. **Data Exploration:** Data visualization with Seaborn, Matplotlib, and Folium.
4. **Machine Learning Prediction:** Model building for outcome prediction.

## Summary of results

* Launch success has improved since 2013.
* KSC LC-39A has the highest success rate among landing sites.
* Orbits ES-L1, GEO, HEO, and SSO have a 100% success rate.
* Most launch sites are near the equator, close to the coast, and at a safe distance from cities and highways.
* All models had the same predictive performance on the test set (accuracy score of 0.833).

---

## Files in this folder

- `1_Data Collection API\`
- `2_Web Scraping\` 
- `3_Data Wrangling\`
- `4_EDA SQL\`
- `5_EDA Data Visualization\`
- `6_Interactive Visual Analytics Folium\`
- `7_Interactive Visual Analytics Plotly\`
- `8_Predictive Analysis\`
- `0_Final Presentation_Alejandro Arango.pdf`

Each of these folders contains a `README.md` and the necessary files for execution.
