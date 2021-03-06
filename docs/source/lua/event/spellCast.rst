
spellCast
========================================================

This event is triggered just before a spell cast is resolved, at the end of the casting animation. It can control the success chance of the spell cast.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

caster
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3reference`_. Read-only. The caster of the spell.

source
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3spell`_. Read-only. The spell information.

castChance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. The percentage chance of the caster successfully casting the spell. May be modified. Setting it to 0 will cause the cast to fail.

weakestSchool
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Number`_. Read-only. Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast.

School IDs can be mapped to skill IDs with ``tes3.magicSchoolSkill[school]``.


Filter
--------------------------------------------------------
This event may be filtered by **source**.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`tes3magicSourceInstance`: ../type/tes3/magicSourceInstance.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3spell`: ../type/tes3/spell.html
