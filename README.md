# CornerStoreGrocery
An application using both C++ and Python that takes input in the form of a text file and can display the data in a Histogram, singularly or  the number of times an item showed up.

The project was creating an easier way to see what items were purchased during the day and in what quantity. The problem was that people could easily make a mistake reading and counting each time an item was purchased. Not only that, but at scale, that method would not be viable and you'd need some sort of system to keep inventory.

I think I did well at designing the overall flow of the application. It works smoothly and had little issues reading and writing from a file.

There are a few features or tweaks that the application could use. The histogram is displayed in the order of the dictionary, so some sorting either descending or ascending would make the data more presentable in some situations.

I think the most difficult part of the project was getting Python and C++ to interact. After that, I've used Python for other projects and C++ we've been learning all term. Integrating the Helper class was a little more challenging that I'm used to, when using other languages. But otherwise, it was simple and definitely has room for improvement. Honestly, the biggest resource for figuring out the Python-C++ connection was the tutorial the instructor provided. It got me all the way there. For classes with the header and cpp files, I used the Zybooks section dealing with header and cpp files.

Reading and writing files in multiple languages I anticipate using again. It was used in previous classes, and will be relevant in the future.

I created a class that holds a lot of print and user input functions so main wasn't flooded with print statements. This enables me to just call the method from the instantiated class member and excecute the print statements without making the code unreadable. Additionally, the code is well-commented and easy to read. 
