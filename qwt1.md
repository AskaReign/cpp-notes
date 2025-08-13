# Today's Qwt Notebook
<!-- ---------------------------------------------------------------------------------- -->
## What is Stack Zooming?
It's a concept realting to how **zoom states** are managed in some interactive plotting tools, including **QwtPlotZoomer**.
When you zoom in (e.g., by drawing a rectangle), the plot records the current view as a **zoom level** or **zoom state**.
These states are stored in a **stack** data structure — think of it like a pile of zoom **“snapshots.”**
- Each new zoom action **pushes** a new zoom rectangle onto the stack.
- When you zoom out (usually by right-click or a “zoom out” command), the zoomer **pops** the top zoom rectangle off the stack, returning to the previous zoom level.
<!-- ---------------------------------------------------------------------------------- -->
## What are Bindings?
In the context of Qwt (a Qt-based plotting library), **bindings** refer to the connections between **input events** (like mouse presses, key presses) and **actions** that happen within the plot or widget.
<!-- ---------------------------------------------------------------------------------- -->
## How does zooming work in Qwt?
### <a href="https://qwt.sourceforge.io/class_qwt_plot_zoomer.html" target="_blank">QwtPlotZoomer</a>
**QwtPlotZoomer** provides **stacked zooming** for a plot widget.
<br><br>
*Inheritance diagram for QwtPlotZoomer*
<br>
![Inheritance diagram for QwtPlotZoomer](./images/QwtPlotZoomer.PNG)
<br>
**QwtPlotZoomer** selects **rectangles** from **user inputs ( mouse or keyboard )** translates them into **plot coordinates** and adjusts the axes to them. The selection is supported by a **rubber band** and optionally by displaying the coordinates of the current mouse position. </br>
Zooming can be repeated as often as possible, limited only by **maxStackDepth()** or **minZoomSize()**. Each rectangle is pushed on a stack.
<br>
<!-- --------------------------------------------------------------------------------------------------------- -->
The default setting how to select rectangles is a **QwtPickerDragRectMachine** with the following bindings:
- **QwtEventPattern::MouseSelect1**
This event pattern binds the mouse to the selection of a rectangle for zooming. Here's the flow:
  - First mouse press (QwtEventPattern::MouseSelect1): The user presses the mouse button at the first point of the zoom rectangle.
  - Second mouse release: The user releases the mouse at the second point of the rectangle. This creates the zoom area, typically defined by the diagonal between the two points.<br><br>
  <i>**Flow of actions:**</i> <br>
  - Mouse Press → Defines the first corner of the rectangle.*
  - Mouse Release → Defines the opposite corner, and the area is selected.
<!-- --------------------------------------------------------------------------------------------------------- -->
- **QwtEventPattern::KeySelect1**
The first key **press** selects the first, the second key **press** selects the second point.
  - **QwtEventPattern::KeyAbort**
**Discard** the selection in the state, where the first point is selected.

