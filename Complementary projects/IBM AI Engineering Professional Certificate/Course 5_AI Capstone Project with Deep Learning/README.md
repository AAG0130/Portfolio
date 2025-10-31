# **Concrete Crack Image Classification**

## Project background and context
Crack detection is important for structural health monitoring and inspection of buildings. Therefore, if we can determine if the concrete images have cracks, preventive action can be taken. 

**Important notice:**  
Documentation within these notebooks was improved, and additional explanatory comments were added to facilitate reproducibility and reading. The **original course assignment design and associated intellectual property belong exclusively to IBM Corporation**. The code logic of the original assignments was kept intact except for minimal corrections necessary to ensure the notebook runs without errors.

---

## Summary of methodologies

1. **Data Loading:** Download dataset of concrete crack images.
2. **Data Preparation:** Image extraction and preprocessing.
3. **Model Training:** Transfer learning using ResNet50 and an addition of a classification head.

## Dataset

* There will be two classes: Images of concrete with cracks and images of concrete with no cracks.
* 40000 RGB images. 20000 with cracks (positives) and 20000 with no cracks (negatives).
* 75% of the images will be used for training, and 25% for validation.

### Dataset challenges
* Cracks can be confused with noise in the background texture or foreign objects.
* Inhomogeneous illumination.
* Irregularities such as exposure of jointing.

---

## Files in this folder

- `1_Data Loading/`
- `2_Data Preparation/` 
- `3_Model Training/`

Each of these folders contains a `README.md` and the necessary files for execution.
