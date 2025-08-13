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
**QwtPlotZoomer** provides **stacked zooming** for a plot widget.<br>
QwtPlotZoomer is tailored for plots with one x and y axis, but it is allowed to attach a second QwtPlotZoomer ( without rubber band and tracker ) for the other axes.
<br><br>
*Inheritance diagram for QwtPlotZoomer*
<br>
![Inheritance diagram for QwtPlotZoomer](./images/QwtPlotZoomer.PNG)
<br>
**QwtPlotZoomer** selects **rectangles** from **user inputs ( mouse or keyboard )** translates them into **plot coordinates** and adjusts the axes to them. The selection is supported by a **rubber band** and optionally by displaying the coordinates of the current mouse position. </br>
Zooming can be repeated as often as possible, limited only by **maxStackDepth()** or **minZoomSize()**. Each rectangle is pushed on a stack.
<br>
<!-- --------------------------------------------------------------------------------------------------------- -->
:black_square_button: The default setting how to select rectangles is a **QwtPickerDragRectMachine** with the following bindings:
- **QwtEventPattern::MouseSelect1**
This event pattern binds the mouse to the selection of a rectangle for zooming. Here's the flow:
  - First mouse press (QwtEventPattern::MouseSelect1): The user presses the mouse button at the first point of the zoom rectangle.
  - Second mouse release: The user releases the mouse at the second point of the rectangle. This creates the zoom area, typically defined by the diagonal between the two points.<br><br>
  <i>**Flow of actions:**</i><br>
  - Mouse Press → Defines the first corner of the rectangle.*
  - Mouse Release → Defines the opposite corner, and the area is selected.
<!-- --------------------------------------------------------------------------------------------------------- -->
- **QwtEventPattern::KeySelect1**
This binding is for selecting the rectangle's corners using the keyboard instead of the mouse. Here's how it works:
  - First key press (QwtEventPattern::KeySelect1): The first key press selects the first point of the zoom rectangle.
  - Second key press: The second key press selects the second point of the rectangle.<br><br>
  <i>**Flow of actions:**</i><br>
  - Key Press → Selects the first point of the rectangle.
  - Key Press → Selects the second point, and the area is defined for zooming.
<!-- --------------------------------------------------------------------------------------------------------- -->
- **QwtEventPattern::KeyAbort**
This binding allows the abortion or cancellation of the selection process using the keyboard:
Key Abort (QwtEventPattern::KeyAbort): If the user presses a key while only the first point has been selected, the selection is discarded and no zoom rectangle is created.<br><br>
  <i>**Flow of actions:**</i><br>
  - Key Press → Discards the selection if only the first point has been selected (i.e., resets the selection).
  
<!-- --------------------------------------------------------------------------------------------------------- --><br>
---

:bullettrain_front: To traverse the zoom stack the following bindings are used:
- **QwtEventPattern::MouseSelect3, QwtEventPattern::KeyUndo**<br>
This binding allows the user to zoom out one level in the zoom stack:<br>
  - **Mouse:** The user can zoom out by clicking the third mouse button (often the middle mouse button, depending on the system configuration).
  - **Keyboard:** The user can also zoom out by pressing the Undo key (often Ctrl + Z or a similar keyboard shortcut, depending on the system or application).

This zooms out one step on the zoom stack (i.e., it takes the view back to a previous zoom level).

---

- **QwtEventPattern::MouseSelect6, QwtEventPattern::KeyRedo**<br>
This binding allows the user to zoom in one level in the zoom stack:<br>
  - **Mouse:** The user can zoom in by clicking the sixth mouse button (some mice have extra buttons that can be mapped to various actions).
  - **Keyboard:** The user can also zoom in by pressing the Redo key (typically Ctrl + Shift + Z or a similar shortcut, depending on the system or application).

This action advances the zoom stack to the next zoom level (i.e., it zooms in to a more focused view).

---

- **QwtEventPattern::MouseSelect2, QwtEventPattern::KeyHome**<br>
This binding allows the user to zoom to the base (original) zoom level:<br>
  - **Mouse:** The user can zoom to the **base level** by clicking the second mouse button (usually mapped to the right-click button).
  - **Keyboard:** The user can also **reset** the zoom to the **base level** by pressing the Home key.

This action resets the zoom to the original or default view, essentially clearing the zoom stack.

---

- The **setKeyPattern()** and **setMousePattern()** functions can be used to configure the zoomer actions. The following example shows, how to configure the 'I' and 'O' keys for zooming in and out one position on the zoom stack. The "Home" key is used to "unzoom" the plot.
```cpp
zoomer = new QwtPlotZoomer( plot );
zoomer->setKeyPattern( QwtEventPattern::KeyRedo, Qt::Key_I, Qt::ShiftModifier );
zoomer->setKeyPattern( QwtEventPattern::KeyUndo, Qt::Key_O, Qt::ShiftModifier );
zoomer->setKeyPattern( QwtEventPattern::KeyHome, Qt::Key_Home );
```

#### QwtPlotZoomer Constructor
The zoomer is initialized with a **QwtPickerDragRectMachine**, the **tracker** mode is set to **QwtPicker::ActiveOnly** and the **rubber band** is set to **QwtPicker::RectRubberBand**.

