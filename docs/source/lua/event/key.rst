
key
========================================================

The **key** event fires when a key up or key down input is detected.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

.. attention:: This event is deprecated. Use the `keyDown`_ and `keyUp`_ events instead!


Event Data
--------------------------------------------------------

keyCode
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The `scan code`_ of the key that raised the event.

pressed
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. True if this is a key down event, false for a key up event.

isControlDown
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. True if control is held.

isShiftDown
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. True if shift is held.

isAltDown
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. True if alt is held.

isSuperDown
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. True if super (Windows key) is held.


Filter
--------------------------------------------------------
This event may be filtered by `keyCode`.

Examples
--------------------------------------------------------

Show a message when Ctrl-Z is pressed.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua
    
    function myOnKeyCallback(e)
        if( e.pressed and e.isControlDown ) then
            tes3.messageBox({ message = "You pressed Ctrl-Z, but you can't undo all your mistakes." })
        end
    end
    -- Filter by scan code 44 to get Z key presses only.
    event.register("key", myOnKeyCallback, { filter = 44 } )

.. _`Event Guide`: ../guide/events.html
.. _`Number`: ../type/lua/number.html
.. _`Boolean`: ../type/lua/boolean.html
.. _`scan code`: ../guide/scancodes.html
.. _`keyDown`: keyDown.html
.. _`keyUp`: keyUp.html