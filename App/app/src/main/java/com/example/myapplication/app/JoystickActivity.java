package com.example.myapplication.app;


import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.util.Log;

public class JoystickActivity extends Activity {

    TextView txtX, txtY;
    JoystickView joystick;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fullscreen);
        txtX = (TextView)findViewById(R.id.TextViewX);
        txtY = (TextView)findViewById(R.id.TextViewY);
        joystick = (JoystickView)findViewById(R.id.joystickView);

        joystick.setOnJostickMovedListener(_listener);
    }

    private JoystickMovedListener _listener = new JoystickMovedListener() {

        @Override
        public void OnMoved(int pan, int tilt) {
            Log.i("moved","moved");
            txtX.setText(Integer.toString(pan));
            txtY.setText(Integer.toString(tilt));
        }

        @Override
        public void OnReleased() {
            txtX.setText("released");
            txtY.setText("released");
        }

        public void OnReturnedToCenter() {
            txtX.setText("stopped");
            txtY.setText("stopped");
        };
    };

}