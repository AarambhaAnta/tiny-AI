# tiny-AI - Vector Database Simulator

A lightweight C++ implementation of a semantic search engine using Euclidean distance and vector embeddings. This project simulates how AI systems like ChatGPT and vector databases find relevant matches by comparing high-dimensional vectors.

## Features

✨ **Semantic Understanding** - Parses natural language queries with keyword-based vectorization
🎯 **Multi-dimensional Vectors** - 4-attribute space: sweetness, crunchiness, saltiness, juiciness
⚡ **Modifier Support** - Understands intensity modifiers: _more, most, less, least_
📊 **Euclidean Distance Matching** - Finds closest matches in vector space
🏆 **Top-3 Results** - Returns best matches with relevance scores
🔤 **Case-Insensitive** - Works with any letter case

## How It Works

1. **Vectorization** - Converts text queries into 4D vectors based on keywords
2. **Distance Calculation** - Computes Euclidean distance between query and product vectors
3. **Ranking** - Sorts products by distance (closest = best match)
4. **Results** - Displays top 3 matches with similarity scores

## How to Run

### Compile

```bash
g++ tinyai.cpp -o tinyai
```

### Run

```bash
./tinyai      # Linux/Mac
.\tinyai.exe  # Windows
```

### Example Queries

```
you: more crunchy
Top matches:
1. chips (score: 4.69)
2. apple (score: 5.74)
3. cake (score: 9.0)

you: less sweet
Top matches:
1. chips (score: 3.61)
2. apple (score: 2.83)
3. cake (score: 7)

you: sweetest
Top matches:
1. cake (score: 5.1)
2. apple (score: 6.55)
3. chips (score: 12.8)
```

## Supported Keywords

### Attributes

- **Sweetness**: sweet, sweeter, sweetest, sour, sorer
- **Crunchiness**: crunchy, crunchier, crunchiest, soft, softer
- **Saltiness**: salty, salt, bland
- **Juiciness**: juicy, juicier, moist, dry

### Modifiers

- **Increase**: more (+2), most (+5)
- **Decrease**: less (-2), least (-5)

## Product Database

| Product | Sweetness | Crunchiness | Saltiness | Juiciness |
| ------- | --------- | ----------- | --------- | --------- |
| Apple   | 7         | 6           | 1         | 7         |
| Chips   | 2         | 9           | 7         | 2         |
| Cake    | 9         | 2           | 1         | 5         |

## Project Structure

```
tinyai.cpp      # Main program
.gitignore      # Excludes build artifacts
README.md       # This file
```

## Technical Details

- **Language**: C++17
- **Dependencies**: Standard Library only
- **Vector Space**: 4 dimensions
- **Distance Metric**: Euclidean (L2 norm)
- **Default Center**: {5, 5, 5, 5} for all attributes

## How Modifiers Work

Modifiers apply **only to the following attribute**:

- `"more crunchy"` → Increases crunchiness by 2
- `"less sweet"` → Decreases sweetness by 2
- `"most juicy"` → Increases juiciness by 5

## Future Enhancements

🔮 Machine learning for word embeddings
📈 Scalable vector database (millions of products)
🗣️ Natural language processing improvements
💾 Persistent storage of query history
📊 User preference learning
🌐 Web interface and REST API
🔐 Authentication and multi-user support

## Example Use Cases

- **E-commerce Search** - Find products matching customer preferences
- **Content Recommendation** - Match user interests to articles/videos
- **Semantic Search** - Find similar documents/queries
- **Chatbot Intent Matching** - Understand user requests

## How to Modify

### Add New Products

Edit the `values` vector in `main()`:

```cpp
vector<vector<int>> values = {
    {7, 6, 1, 7},     // apple
    {2, 9, 7, 2},     // chips
    {9, 2, 1, 5},     // cake
    {5, 4, 3, 6}      // new product
};
```

### Add New Keywords

Add entries to the `keywords` vector in `vectorizeques()`:

```cpp
{"bitter", {2, -3}},    // tartness dimension, decrease by 3
{"fluffy", {1, -2}}     // crunchiness dimension, decrease by 2
```

## Learning Value

This project demonstrates:

- ✅ Vector embeddings (core AI concept)
- ✅ Euclidean distance calculation
- ✅ Natural language processing basics
- ✅ Data structure design
- ✅ Algorithm optimization

Perfect for learning how semantic search and vector databases work!

## License

Open source - Feel free to modify and learn!

## Author

Created as an AI learning project exploring vector databases and semantic search.

---

Try it now! `git clone https://github.com/absumit/tiny-AI.git`
