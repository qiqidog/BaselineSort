# BaselineSort
BaselineSort (Segment Sort) — A novel sorting algorithm variant based on segment height and baseline accumulation.

## Core Idea
We treat every number as the height of a vertical line segment:
1. Maintain a global baseline variable `baseSum`, initialized to 0.
2. Find the minimum remaining height among all active non-zero segments.
3. Raise the baseline by adding this minimum height to `baseSum`.
4. Subtract this minimum height from every remaining active segment.
5. If a segment height becomes zero after subtraction, its original value equals the current `baseSum`. Save this baseline value into sorted result.
6. Call `moveLeft` to shift all non-zero segments to the left, zeros move to the right.
7. Repeat until all segments are collected.

## Properties
- Time Complexity: $O(n^2)$
- Space Complexity: $O(n)$
- Stable: ❌ Unstable sort
- Not in-place
- Category: Selection sort variant, educational / toy algorithm

> This algorithm is for learning and demonstration purposes only. It is not optimized for large datasets.

## Example
Input array: `[3, 2, 1, 4]`
Ascending output: `[1, 2, 3, 4]`
Descending output: `[4, 3, 2, 1]`

Support duplicate numbers:
Input: `[4, 2, 2, 5]`
Ascending output: `[2, 2, 4, 5]`

## Implementations
- Swift: `BaselineSort.swift`
- C++: `BaselineSort.cpp`

## License
MIT License
